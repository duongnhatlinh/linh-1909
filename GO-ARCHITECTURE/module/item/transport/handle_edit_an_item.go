package todotrpt

import (
	"GO-ARCHITECTURE/common"
	"GO-ARCHITECTURE/component/appctx"
	todobiz "GO-ARCHITECTURE/module/item/business"
	todomodel "GO-ARCHITECTURE/module/item/model"
	todostorage "GO-ARCHITECTURE/module/item/storage"
	"github.com/gin-gonic/gin"
	"net/http"
)

func HandleEditAnItem(appCtx appctx.AppContext) gin.HandlerFunc {
	return func(ctx *gin.Context) {
		uid, err := common.FromBase58(ctx.Param("id"))

		//id, err := strconv.Atoi(ctx.Param("id"))

		if err != nil {
			ctx.JSON(http.StatusBadRequest, gin.H{"error": err.Error()})
			return
		}

		var data todomodel.UpdateTodoItem
		if err := ctx.ShouldBind(&data); err != nil {
			ctx.JSON(http.StatusBadRequest, gin.H{"error": err.Error()})
			return
		}

		//data.Title = strings.TrimSpace(data.Title)

		store := todostorage.NewMySQLStorage(appCtx.GetMainDBConnect())
		biz := todobiz.NewEditTodoItemStorage(store)

		if err := biz.EditAnItem(ctx.Request.Context(), &data, int(uid.GetLocalID())); err != nil {
			ctx.JSON(http.StatusNotFound, gin.H{"error": err.Error()})
			return
		}

		ctx.JSON(http.StatusOK, common.SimpleSuccessRes(true))
	}
}
