package todobiz

import (
	todomodel "GO-ARCHITECTURE/module/item/model"
	"context"
	"errors"
)

type DeleteTodoItemStorage interface {
	FindItemByCondition(ctx context.Context,
		condition map[string]interface{},
		moreKeys ...string,
	) (*todomodel.ToDoItem, error)

	DeleteItem(ctx context.Context, id int) error
}

type deleteBiz struct {
	store DeleteTodoItemStorage
}

func NewDeleteTodoItemStorage(store DeleteTodoItemStorage) *deleteBiz {
	return &deleteBiz{store: store}
}

func (biz *deleteBiz) DeleteAnItem(ctx context.Context, id int) error {
	olddata, err := biz.store.FindItemByCondition(ctx, map[string]interface{}{"id": id})

	if err != nil {
		return nil
	}

	if olddata.Status == 0 {
		return errors.New("item deleted")
	}

	if err := biz.store.DeleteItem(ctx, id); err != nil {
		return err
	}

	return nil
}
