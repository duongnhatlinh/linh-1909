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

func HandleDeleteAnItem(appCtx appctx.AppContext) gin.HandlerFunc {
	return func(ctx *gin.Context) {
		uid, err := common.FromBase58(ctx.Param("id"))

		//id, err := strconv.Atoi(ctx.Param("id"))

		if err != nil {
			ctx.JSON(http.StatusBadRequest, gin.H{"error": err.Error()})
			return
		}

		var data todomodel.DeleteTodoItem

		if err := ctx.ShouldBind(&data); err != nil {
			ctx.JSON(http.StatusBadRequest, gin.H{"error": err.Error()})
			return
		}

		store := todostorage.NewMySQLStorage(appCtx.GetMainDBConnect())
		biz := todobiz.NewDeleteTodoItemStorage(store)

		if err := biz.DeleteAnItem(ctx.Request.Context(), int(uid.GetLocalID())); err != nil {
			ctx.JSON(http.StatusBadRequest, gin.H{"error": err.Error()})
			return
		}

		ctx.JSON(http.StatusOK, gin.H{"delete": true})
	}
}
