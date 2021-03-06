# Кращі продавці

Компанії, які продають свою продукцію на trifles.com, можуть аналізувати відгуки клієнтів щодо своєї продукції в режимі реального часу. Уявіть, що компанія Trifles створює категорію під назвою "продавці вищого гатунку", яка відображатиме лише товари, що продаються компаніями, чий середній відсоток п'ятизіркових відгуків за товар перевищує певний поріг. Враховуючи кількість п’ятизіркових та загальну кількість відгуків для кожного товару, який компанія продає, а також пороговий відсоток, якою є мінімальна кількість додаткових п’ятизіркових оглядів, необхідних компанії, щоб стати продавцем вищого гатунку?

## Приклад

Припустимо, є 3 товари (n = 3), де рейтингу товарів [[4, 4], [1, 2], [3, 6]], а процентний поріг 77. Перше число для кожного товару позначає кількість п'ятизіркових відгуків, а друга - загальну кількість відгуків. Ось як ми можемо змусити продавця досягти межі з мінімальною кількістю додаткових п'ятизіркових відгуків:

* Перш ніж ми додамо більше п'ятизіркових відгуків, відсоток для цього продавця складає ((4/4) + (1/2) + (3/6)) / 3 = 66,66%

* Якщо до другого відгуку додати п'ятизірковий відгук, відсоток зросте до ((4/4) + (2/3) + (3/6)) / 3 = 72,22%

* Якщо до другого продукту додати ще один відгук із п’ятьма зірками, відсоток зросте до ((4/4) + (3/4) + (3/6)) / 3 = 75,00%

* Якщо до третього продукту додати п'ятизірковий відгук, відсоток зросте до ((4/4) + (3/4) + (4/7)) / 3 = 77,38%

На даний момент досягнуто межі 77%. Отже, відповідь 3, оскільки це мінімальна кількість додаткових п’ятизіркових відгуків, з якими компанія повинна стати продавцем вищого гатунку.
