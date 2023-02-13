package restaurantlikestorage

import (
	"GO-ARCHITECTURE/common"
	restaurantlikemodel "GO-ARCHITECTURE/module/restaurantlike/model"
	"context"
)

func (s *mysqlStorage) GetRestaurantLike(ctx context.Context, ids []int) (map[int]int, error) {
	data := make(map[int]int)

	type sqlData struct {
		RestaurantId int `gorm:"column:restaurant_id"`
		LikeCount    int `gorm:"column:count"`
	}

	var listLike []sqlData

	if err := s.db.Table(restaurantlikemodel.Like{}.TableName()).
		Select("restaurant_id, count(restaurant_id) as count").
		Where("restaurant_id in (?)", ids).
		Group("restaurant_id").
		Find(&listLike).Error; err != nil {
		return nil, common.ErrDb(err)
	}

	for _, item := range listLike {
		data[item.RestaurantId] = item.LikeCount
	}

	return data, nil
	//return nil, errors.New("cannot get like restaurants")
}
