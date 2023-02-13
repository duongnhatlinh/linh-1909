package todobiz

import (
	"GO-ARCHITECTURE/common"
	todomodel "GO-ARCHITECTURE/module/item/model"
	"context"
)

type FindTodoItemStorage interface {
	FindItemByCondition(ctx context.Context,
		condition map[string]interface{},
		moreKeys ...string,
	) (*todomodel.ToDoItem, error)
}

type findBiz struct {
	store FindTodoItemStorage
}

func NewFindTodoItemStorage(store FindTodoItemStorage) *findBiz {
	return &findBiz{store: store}
}

func (biz *findBiz) FindAnItem(ctx context.Context, id int) (*todomodel.ToDoItem, error) {
	data, err := biz.store.FindItemByCondition(ctx, map[string]interface{}{"id": id})

	if err != nil {
		if err != common.RecordNotFound {
			return nil, common.ErrCannotGetEntity(todomodel.EntityName, err)
		}

		return nil, common.ErrCannotGetEntity(todomodel.EntityName, err)
	}

	if data.Status == 0 {
		return nil, common.ErrEntityDeleted(todomodel.EntityName, err)
	}

	return data, err
}
