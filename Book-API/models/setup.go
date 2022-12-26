package models

import (
	"gorm.io/driver/mysql"
	"gorm.io/gorm"
	"log"
)

func ConnectDB() *gorm.DB {
	dsn := "root:0966314211@tcp(127.0.0.1:3306)/book?charset=utf8mb4&parseTime=True&loc=Local"
	db, err := gorm.Open(mysql.Open(dsn), &gorm.Config{})

	if err != nil {
		log.Fatal("Cannot connect to DB")
	}

	log.Println("Connect DB:", db)

	return db
}
