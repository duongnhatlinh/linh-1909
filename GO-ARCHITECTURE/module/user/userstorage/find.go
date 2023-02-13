package userstorage

import (
	"GO-ARCHITECTURE/common"
	"GO-ARCHITECTURE/module/user/usermodel"
	"golang.org/x/net/context"
)

func (s *mysqlStorage) FindUser(ctx context.Context, condition map[string]interface{}, moreInfo ...string) (*usermodel.User, error) {
	db := s.db.Table(usermodel.User{}.TableName())

	for i := range moreInfo {
		db = db.Preload(moreInfo[i])
	}

	var user usermodel.User

	if err := db.Where(condition).First(&user).Error; err != nil {
		return nil, common.ErrDb(err)
	}

	return &user, nil
}
