## Завдання
Знайдіть помилку (помилки) та змініть один рядок коду в неправильній реалізації функції, яка повинна повертати найменший елемент даного непорожнього масиву Array, який містить щонайбільше 1000 цілих чисел у діапазоні [-1000..1000 ].
Зверніть увагу, що для прикладу тесту Array = [-1, 1, -2, 2] доданий код вже повертає правильну відповідь (-2).

## Реалізація функціі
```go
package smlstlmnt

// SmallestElement returns integer
func SmallestElement(Array []int) int {
  var result int = 0
  for i := 1; i < len(Array); i++ {
    if result > Array[i] {
      result = Array[i]
    }
  }
  return result
}
```