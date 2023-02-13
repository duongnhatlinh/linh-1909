package todobiz

import (
	todomodel "GO-ARCHITECTURE/module/item/model"
	"context"
	"errors"
)

type EditTodoItemStorage interface {
	FindItemByCondition(ctx context.Context,
		condition map[string]interface{},
		moreKeys ...string,
	) (*todomodel.ToDoItem, error)

	EditItem(ctx context.Context,
		data *todomodel.UpdateTodoItem,
		id int) error
}

type editBiz struct {
	store EditTodoItemStorage
}

func NewEditTodoItemStorage(store EditTodoItemStorage) *editBiz {
	return &editBiz{store: store}
}

func (biz *editBiz) EditAnItem(ctx context.Context, data *todomodel.UpdateTodoItem, id int) error {
	olddata, err := biz.store.FindItemByCondition(ctx, map[string]interface{}{"id": id})

	if err != nil {
		return err
	}

	if olddata.Status == 0 {
		return errors.New("data deleted")
	}

	//if data.Title == "" {
	//	return errors.New("title can not be blank")
	//}

	if err := biz.store.EditItem(ctx, data, id); err != nil {
		return err
	}
	return nil
}
