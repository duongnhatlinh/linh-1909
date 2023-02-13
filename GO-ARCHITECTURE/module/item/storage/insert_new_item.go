package todostorage

import (
	"GO-ARCHITECTURE/common"
	todomodel "GO-ARCHITECTURE/module/item/model"
	"context"
)

func (s *mysqlStorage) CreateItem(ctx context.Context, data *todomodel.CreateTodoItem) error {
	if err := s.db.Create(data).Error; err != nil {
		return common.ErrDb(err)
	}
	return nil
}
