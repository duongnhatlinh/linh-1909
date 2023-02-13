package common

type successRes struct {
	Data   interface{} `json:"data"`
	Paging interface{} `json:"paging,omitempty"`
	Filter interface{} `json:"filter,omitempty"`
}

func NewSuccessRes(data, paging, filter interface{}) *successRes {
	return &successRes{Data: data, Paging: paging, Filter: filter}
}

func SimpleSuccessRes(data interface{}) *successRes {
	return &successRes{data, nil, nil}
}
