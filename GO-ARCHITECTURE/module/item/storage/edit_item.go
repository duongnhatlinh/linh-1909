package todostorage

import (
	"GO-ARCHITECTURE/common"
	todomodel "GO-ARCHITECTURE/module/item/model"
	"context"
)

func (s *mysqlStorage) EditItem(ctx context.Context,
	data *todomodel.UpdateTodoItem,
	id int,
) error {
	if err := s.db.Where("id= ?", id).Updates(data).Error; err != nil {
		return common.ErrDb(err)
	}
	return nil
}
