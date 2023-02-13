package todostorage

import (
	"GO-ARCHITECTURE/common"
	todomodel "GO-ARCHITECTURE/module/item/model"
	"context"
	"gorm.io/gorm"
)

func (s *mysqlStorage) FindItemByCondition(ctx context.Context,
	condition map[string]interface{},
	moreKeys ...string,
) (*todomodel.ToDoItem, error) {
	var data todomodel.ToDoItem

	if err := s.db.Where(condition).First(&data).Error; err != nil {
		if err == gorm.ErrRecordNotFound {
			return nil, common.RecordNotFound
		}
		return nil, common.ErrDb(err)
	}
	return &data, nil
}
