package todostorage

import (
	"GO-ARCHITECTURE/common"
	todomodel "GO-ARCHITECTURE/module/item/model"
	"context"
)

func (s *mysqlStorage) DeleteItem(ctx context.Context, id int) error {

	if err := s.db.
		Table(todomodel.DeleteTodoItem{}.TableName()).
		Where("id = ?", id).
		Updates(map[string]interface{}{"status": 0}).
		Error; err != nil {
		return common.ErrDb(err)
	}

	return nil
}
