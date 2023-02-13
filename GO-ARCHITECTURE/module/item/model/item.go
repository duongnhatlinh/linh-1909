package todomodel

import "GO-ARCHITECTURE/common"

const EntityName = "TodoItem"

type ToDoItem struct {
	common.SQLModel `json:",inline"`
	Name            string         `json:"name" gorm:"name" gorm:"column:name;"`
	Addr            string         `json:"address" gorm:"column:addr;"`
	Logo            *common.Image  `json:"logo" gorm:"column:logo;"`
	Cover           *common.Images `json:"cover" gorm:"column:cover;"`
	LikeCount       int            `json:"like_count" gorm:"-"`
}

func (ToDoItem) TableName() string {
	return "restaurants"
}

type UpdateTodoItem struct {
	Name  *string        `json:"name" gorm:"name" gorm:"column:name;"`
	Addr  *string        `json:"address" gorm:"column:addr;"`
	Logo  *common.Image  `json:"logo" gorm:"column:logo;"`
	Cover *common.Images `json:"cover" gorm:"column:cover;"`
}

func (UpdateTodoItem) TableName() string {
	return ToDoItem{}.TableName()
}

type CreateTodoItem struct {
	common.SQLModel `json:",inline"`
	Name            string         `json:"name" gorm:"name" gorm:"column:name;"`
	Addr            string         `json:"address" gorm:"column:addr;"`
	Logo            *common.Image  `json:"logo" gorm:"column:logo;"`
	Cover           *common.Images `json:"cover" gorm:"column:cover;"`
}

func (CreateTodoItem) TableName() string {
	return ToDoItem{}.TableName()
}

type DeleteTodoItem struct {
	Status int `json:"status" gorm:"column:status;"`
}

func (DeleteTodoItem) TableName() string {
	return ToDoItem{}.TableName()
}

func (data *ToDoItem) Mask(isAdminOrOwner bool) {
	data.GenUID(common.DbTypeRestaurant)
}

func (data *CreateTodoItem) Mask(isAdminOrOwner bool) {
	data.GenUID(common.DbTypeRestaurant)
}
