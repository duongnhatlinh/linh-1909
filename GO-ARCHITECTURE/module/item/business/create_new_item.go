package todobiz

import (
	todomodel "GO-ARCHITECTURE/module/item/model"
	"context"
	"errors"
)

type CreateTodoItemStorage interface {
	CreateItem(ctx context.Context, data *todomodel.CreateTodoItem) error
}

type createBiz struct {
	store CreateTodoItemStorage
}

func NewCreateToDoItemBiz(store CreateTodoItemStorage) *createBiz {
	return &createBiz{store: store}
}

func (biz *createBiz) CreateNewItem(ctx context.Context, data *todomodel.CreateTodoItem) error {
	if data.Name == "" {
		return errors.New("title can not be blank")
	}

	// do not allow "finished" status when creating a new task
	//data.Status = 1 // set to default

	if err := biz.store.CreateItem(ctx, data); err != nil {
		return err
	}
	return nil
}
