package controllers

import (
	"Book-API/models"
	"github.com/gin-gonic/gin"
	"gorm.io/gorm"
	"net/http"
	"strconv"
	"strings"
)

func SetupRouter() *gin.Engine {
	db := models.ConnectDB()
	router := gin.Default()

	router.POST("/api/books", creatBook(db))
	router.GET("/api/books/:id", getBook(db))
	router.GET("/api/books", getListBook(db))
	router.PUT("/api/books/:id", updateBook(db))
	router.DELETE("/api/books/:id", deleteBook(db))

	return router
}

func creatBook(db *gorm.DB) gin.HandlerFunc {
	return func(c *gin.Context) {
		var item models.Book

		if err := c.ShouldBind(&item); err != nil {
			c.JSON(http.StatusBadRequest, gin.H{"error": err.Error()})
			return
		}

		item.Title = strings.TrimSpace(item.Title)
		item.Author = strings.TrimSpace(item.Author)
		if item.Title == "" || item.Author == "" {
			c.JSON(http.StatusBadRequest, gin.H{"error": "Title, Author not be blank"})
			return
		}

		if err := db.Create(&item).Error; err != nil {
			c.JSON(http.StatusBadRequest, gin.H{"error": err.Error()})
			return
		}
		c.JSON(http.StatusOK, gin.H{"book": item})
	}
}

func getBook(db *gorm.DB) gin.HandlerFunc {
	return func(c *gin.Context) {
		id, err := strconv.Atoi(c.Param("id"))
		if err != nil {
			c.JSON(http.StatusNotFound, gin.H{"error": err.Error()})
			return
		}

		var item models.Book
		if err := db.Where("id = ?", id).First(&item).Error; err != nil {
			c.JSON(http.StatusNotFound, gin.H{"error": err.Error()})
			return
		}
		c.JSON(http.StatusOK, gin.H{"book": item})
	}
}

func getListBook(db *gorm.DB) gin.HandlerFunc {
	return func(c *gin.Context) {
		var listItem []models.Book
		if err := db.Find(&listItem).Error; err != nil {
			c.JSON(http.StatusNotFound, gin.H{"error": err.Error()})
			return
		}
		c.JSON(http.StatusOK, gin.H{"books": listItem})
	}
}

func updateBook(db *gorm.DB) gin.HandlerFunc {
	return func(c *gin.Context) {
		id, err := strconv.Atoi(c.Param("id"))
		if err != nil {
			c.JSON(http.StatusNotFound, gin.H{"error": err.Error()})
			return
		}

		var item models.Book
		if err := c.ShouldBind(&item); err != nil {
			c.JSON(http.StatusBadRequest, gin.H{"error": err.Error()})
			return
		}

		if err := db.Where("id = ?", id).Updates(&item).Error; err != nil {
			c.JSON(http.StatusNotFound, gin.H{"error": err.Error()})
			return
		}
		c.JSON(http.StatusOK, gin.H{"book": item})
	}
}

func deleteBook(db *gorm.DB) gin.HandlerFunc {
	return func(c *gin.Context) {
		id, err := strconv.Atoi(c.Param("id"))
		if err != nil {
			c.JSON(http.StatusNotFound, gin.H{"error": err.Error()})
			return
		}

		var item models.Book
		if err := db.Where("id = ?", id).Delete(&item).Error; err != nil {
			c.JSON(http.StatusBadRequest, gin.H{"error": err.Error()})
			return
		}
		c.JSON(http.StatusOK, gin.H{"book": item})
	}
}
