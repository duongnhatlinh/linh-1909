package todotrpt

import (
	"GO-ARCHITECTURE/common"
	"GO-ARCHITECTURE/component/appctx"
	"net/http"
	"strings"

	todobiz "GO-ARCHITECTURE/module/item/business"
	todomodel "GO-ARCHITECTURE/module/item/model"
	todostorage "GO-ARCHITECTURE/module/item/storage"
	"github.com/gin-gonic/gin"
)

func HandleCreateItem(appCtx appctx.AppContext) gin.HandlerFunc {
	return func(c *gin.Context) {
		var dataItem todomodel.CreateTodoItem

		if err := c.ShouldBind(&dataItem); err != nil {
			c.JSON(http.StatusBadRequest, gin.H{"error": err.Error()})
			return
		}

		// preprocess name- trim all spaces
		dataItem.Name = strings.TrimSpace(dataItem.Name)

		// setup dependencies
		storage := todostorage.NewMySQLStorage(appCtx.GetMainDBConnect())
		biz := todobiz.NewCreateToDoItemBiz(storage)

		if err := biz.CreateNewItem(c.Request.Context(), &dataItem); err != nil {
			c.JSON(http.StatusBadRequest, gin.H{"error": err.Error()})
			return
		}

		dataItem.Mask(false)

		c.JSON(http.StatusOK, common.SimpleSuccessRes(dataItem.FakeID.String()))
	}
}
