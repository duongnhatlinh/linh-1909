package todotrpt

import (
	"GO-ARCHITECTURE/common"
	"GO-ARCHITECTURE/component/appctx"
	todobiz "GO-ARCHITECTURE/module/item/business"
	todostorage "GO-ARCHITECTURE/module/item/storage"
	"github.com/gin-gonic/gin"
	"net/http"
)

func HandleFindItem(appCtx appctx.AppContext) gin.HandlerFunc {
	return func(ctx *gin.Context) {
		uid, err := common.FromBase58(ctx.Param("id"))

		//id, err := strconv.Atoi(ctx.Param("id"))

		if err != nil {
			panic(common.ErrInvalidRequest(err))
		}

		store := todostorage.NewMySQLStorage(appCtx.GetMainDBConnect())
		biz := todobiz.NewFindTodoItemStorage(store)

		data, err := biz.FindAnItem(ctx.Request.Context(), int(uid.GetLocalID()))

		if err != nil {
			panic(err)
		}

		data.Mask(false)

		ctx.JSON(http.StatusOK, gin.H{"data": data})
	}
}
