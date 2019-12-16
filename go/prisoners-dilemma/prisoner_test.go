package dilemma

import "testing"

func Test_remain_silent_responds_with_no_suspect_testimony(t *testing.T) {
  prisoner := Prisoner {}
  accomplice := Prisoner {}
  testimony := prisoner.RemainSilent(&accomplice)
  if testimony.Suspect != nil {
    t.Error(testimony)
  }
}

func Test_testify_responds_with_the_accomplice_as_the_suspect_testimony(t *testing.T) {
  prisoner := Prisoner {}
  accomplice := Prisoner {}
  testimony := prisoner.Testify(&accomplice)
  if testimony.Suspect != &accomplice {
    t.Error(testimony)
  }
}
