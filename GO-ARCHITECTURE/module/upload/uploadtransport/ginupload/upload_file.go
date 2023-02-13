package ginupload

import (
	"GO-ARCHITECTURE/common"
	"GO-ARCHITECTURE/component/appctx"
	"fmt"
	"github.com/gin-gonic/gin"
)

func Upload(appCtx appctx.AppContext) func(ctx *gin.Context) {
	return func(c *gin.Context) {
		fileHeader, err := c.FormFile("file")

		if err != nil {
			panic(common.ErrInvalidRequest(err))
		}

		c.SaveUploadedFile(fileHeader, fmt.Sprint("./static/%s", fileHeader.Filename))
		c.JSON(200, common.SimpleSuccessRes(true))
	}
}
