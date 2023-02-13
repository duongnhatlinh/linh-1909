package ginuser

import (
	"GO-ARCHITECTURE/common"
	"GO-ARCHITECTURE/component/appctx"
	"GO-ARCHITECTURE/component/hasher"
	"GO-ARCHITECTURE/module/user/userbiz"
	"GO-ARCHITECTURE/module/user/usermodel"
	"GO-ARCHITECTURE/module/user/userstorage"
	"github.com/gin-gonic/gin"
	"net/http"
)

func Register(appCtx appctx.AppContext) func(ctx *gin.Context) {
	return func(c *gin.Context) {
		db := appCtx.GetMainDBConnect()
		var data usermodel.UserCreate

		if err := c.ShouldBind(&data); err != nil {
			c.JSON(http.StatusBadRequest, common.ErrInvalidRequest(err))
		}

		store := userstorage.NewMysqlStorage(db)
		md5 := hasher.NewMd5Hash()
		biz := userbiz.NewRegisterBusiness(store, md5)

		if err := biz.Register(c.Request.Context(), &data); err != nil {
			c.JSON(http.StatusBadRequest, err)
			return
		}

		data.Mask(false)

		c.JSON(200, common.SimpleSuccessRes(data.FakeID.String()))
	}
}
