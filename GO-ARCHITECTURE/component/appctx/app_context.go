package appctx

import "gorm.io/gorm"

type AppContext interface {
	GetMainDBConnect() *gorm.DB
	SecretKey() string
}

type appCtx struct {
	db        *gorm.DB
	secretKey string
}

func NewAppCtx(db *gorm.DB, secretKey string) *appCtx {
	return &appCtx{db: db,
		secretKey: secretKey,
	}
}

func (ctx *appCtx) GetMainDBConnect() *gorm.DB {
	return ctx.db
}

func (ctx *appCtx) SecretKey() string {
	return ctx.secretKey
}
