package userstorage

import (
	"GO-ARCHITECTURE/common"
	"GO-ARCHITECTURE/module/user/usermodel"
	"context"
)

func (s *mysqlStorage) CreateUser(ctx context.Context, data *usermodel.UserCreate) error {
	db := s.db.Begin()

	if err := db.Table(data.TableName()).Create(&data).Error; err != nil {
		db.Rollback()
		return common.ErrDb(err)
	}

	if err := db.Commit().Error; err != nil {
		db.Rollback()
		return common.ErrDb(err)
	}

	return nil
}
