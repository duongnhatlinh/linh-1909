package main

import (
	"Book-API/controllers"
	"github.com/gin-gonic/gin"
	"net/http"
)

func main() {
	r := controllers.SetupRouter()

	r.GET("/", func(c *gin.Context) {
		c.JSON(http.StatusOK, gin.H{
			"message": "practice rest api with go",
		})
	})

	r.Run()
}
