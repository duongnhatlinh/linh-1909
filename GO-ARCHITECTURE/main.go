package main

import (
	"GO-ARCHITECTURE/component/appctx"
	"GO-ARCHITECTURE/middleware"
	todotrpt "GO-ARCHITECTURE/module/item/transport"
	"GO-ARCHITECTURE/module/upload/uploadtransport/ginupload"
	"GO-ARCHITECTURE/module/user/usertransport/ginuser"
	"github.com/gin-gonic/gin"
	"gorm.io/driver/mysql"
	"gorm.io/gorm"
	"log"
	"os"
)

func main() {
	dsn := "root:0966314211@tcp(127.0.0.1:3306)/todo_db?charset=utf8mb4&parseTime=True&loc=Local"
	db, err := gorm.Open(mysql.Open(dsn), &gorm.Config{})

	secretKey := os.Getenv("SECRET_SYSTEM")

	if err != nil {
		log.Fatalln("Cannot connect to MySQL:", err)
	}
	appCtx := appctx.NewAppCtx(db, secretKey)

	router := gin.Default()
	router.Use(middleware.Recover(appCtx))

	router.POST("/upload", ginupload.Upload(appCtx))

	router.POST("/register", ginuser.Register(appCtx))
	router.POST("/login", ginuser.Login(appCtx))

	v1 := router.Group("/v1")
	{
		v1.POST("/items", todotrpt.HandleCreateItem(appCtx))
		v1.GET("items/new", todotrpt.HandleListItems(appCtx))
		v1.GET("/items/:id", todotrpt.HandleFindItem(appCtx))
		v1.GET("/items", todotrpt.HandleListItems(appCtx))
		v1.PUT("/items/:id", todotrpt.HandleEditAnItem(appCtx))
		v1.DELETE("/items/:id", todotrpt.HandleDeleteAnItem(appCtx))
	}
	router.Run()
}
