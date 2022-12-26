package models

import "time"

type Book struct {
	Id        int       `json:"id" gorm:"column:id;"`
	Title     string    `json:"title" gorm:"column:title;"`
	Author    string    `json:"author" gorm:"column:author;"`
	CreatedAt time.Time `json:"created_at" gorm:"column:created_at;"`
	UpdatedAt time.Time `json:"updated_at" gorm:"column:updated_at;"`
}
