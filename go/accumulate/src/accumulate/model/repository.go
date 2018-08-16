package model

import (
  "github.com/satori/go.uuid"
)

// Repository stores accumulators
type Repository struct {
  Accumulators map[string]uint64
}

// NewRepository creates new empty repository
func NewRepository() Repository {
  return Repository{
    Accumulators: make(map[string]uint64),
  }
}

// NewAccumulator creates new accumulator and adds it to the repository
func (repository Repository) NewAccumulator() Accumulator {
  accumulator := Accumulator{
    ID:    uuid.Must(uuid.NewV4()).String(),
    Value: 0,
  }
  repository.Accumulators[accumulator.ID] = accumulator.Value
  return accumulator
}

// GetAccumulator returns accumulator with specified id
func (repository Repository) GetAccumulator(id string) Accumulator {
  return Accumulator{
    ID:    id,
    Value: repository.Accumulators[id],
  }
}

// UpdateAccumulator updates specified accumulator
func (repository Repository) UpdateAccumulator(accumulator Accumulator) {
  repository.Accumulators[accumulator.ID] = accumulator.Value
}

// DeleteAccumulator deletes specified accumulator
func (repository Repository) DeleteAccumulator(accumulator Accumulator) {
  delete(repository.Accumulators, accumulator.ID)
}
