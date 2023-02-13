package todobiz

import (
	"GO-ARCHITECTURE/common"
	todomodel "GO-ARCHITECTURE/module/item/model"
	"context"
	"log"
)

type ListTodoItemStorage interface {
	List(ctx context.Context,
		conditions map[string]interface{},
		filter *todomodel.Filter,
		paging *common.Paging,
		moreKeys ...string,
	) ([]todomodel.ToDoItem, error)
}

type LikeStorage interface {
	GetRestaurantLike(ctx context.Context, ids []int) (map[int]int, error)
}

type listBiz struct {
	store     ListTodoItemStorage
	likeStore LikeStorage
}

func NewListTodoItemStorage(store ListTodoItemStorage, likeStore LikeStorage) *listBiz {
	return &listBiz{store: store, likeStore: likeStore}
}

func (biz *listBiz) ListItems(
	ctx context.Context,
	filter *todomodel.Filter,
	paging *common.Paging,
) ([]todomodel.ToDoItem, error) {
	data, err := biz.store.List(ctx, nil, filter, paging)

	if err != nil {
		return nil, common.ErrCannotListEntity(todomodel.EntityName, err)
	}

	ids := make([]int, len(data))

	for i := range data {
		ids[i] = data[i].Id
	}

	mapResLike, err := biz.likeStore.GetRestaurantLike(ctx, ids)

	if err != nil {
		log.Println("Cannot get restaurant likes", err)
	}

	if v := mapResLike; v != nil {
		for i, item := range data {
			data[i].LikeCount = mapResLike[item.Id]
		}
	}

	return data, nil
}
