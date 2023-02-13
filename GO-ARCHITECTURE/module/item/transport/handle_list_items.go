package todotrpt

import (
	"GO-ARCHITECTURE/common"
	"GO-ARCHITECTURE/component/appctx"
	todobiz "GO-ARCHITECTURE/module/item/business"
	todomodel "GO-ARCHITECTURE/module/item/model"
	todostorage "GO-ARCHITECTURE/module/item/storage"
	restaurantlikestorage "GO-ARCHITECTURE/module/restaurantlike/storage"
	"github.com/gin-gonic/gin"
	"net/http"
)

func HandleListItems(appCtx appctx.AppContext) gin.HandlerFunc {
	return func(ctx *gin.Context) {
		var filter todomodel.Filter

		if err := ctx.ShouldBind(&filter); err != nil {
			ctx.JSON(http.StatusBadRequest, gin.H{"error": err.Error()})
			return
		}

		var paging common.Paging

		if err := ctx.ShouldBind(&paging); err != nil {
			ctx.JSON(http.StatusBadRequest, gin.H{"error": err.Error()})
			return
		}

		paging.Fulfill()

		store := todostorage.NewMySQLStorage(appCtx.GetMainDBConnect())
		likeStore := restaurantlikestorage.NewMySQLStorage(appCtx.GetMainDBConnect())
		biz := todobiz.NewListTodoItemStorage(store, likeStore)

		data, err := biz.ListItems(ctx.Request.Context(), &filter, &paging)

		if err != nil {
			ctx.JSON(http.StatusBadRequest, gin.H{"error": err.Error()})
			return
		}

		for i := range data {
			data[i].Mask(false)

			if i == len(data)-1 {
				paging.NextCursor = data[i].FakeID.String()
			}
		}

		ctx.JSON(http.StatusOK, common.NewSuccessRes(data, paging, filter))
	}
}
