package todostorage

import (
	"GO-ARCHITECTURE/common"
	todomodel "GO-ARCHITECTURE/module/item/model"
	"context"
)

func (s *mysqlStorage) List(ctx context.Context,
	conditions map[string]interface{},
	filter *todomodel.Filter,
	paging *common.Paging,
	moreKeys ...string,
) ([]todomodel.ToDoItem, error) {
	var data []todomodel.ToDoItem

	db := s.db

	for i := range moreKeys {
		db = db.Preload(moreKeys[i])
	}

	db = db.Table(todomodel.ToDoItem{}.TableName()).Where(conditions)

	if v := filter; v != nil {
		if v.CityId > 0 {
			db = db.Where("city_id = ?", v.CityId)
		}
	}

	if err := db.Count(&paging.Total).Error; err != nil {
		return nil, common.ErrDb(err)
	}

	if f := paging.FakeCursor; f != "" {
		if uid, err := common.FromBase58(f); err == nil {
			db = db.Where("id < ?", uid.GetLocalID())
		}
	} else {
		db = db.Offset((paging.Page - 1) * paging.Limit)
	}

	if err := db.
		Limit(paging.Limit).
		Order("id desc").
		Find(&data).Error; err != nil {
		return nil, common.ErrDb(err)
	}
	return data, nil
}
