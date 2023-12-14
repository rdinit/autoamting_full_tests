# Автоматизированные тесты
Данный workflow позволяет тестировать ваши классы сразу на разных тестах и записывать результат в ```test_output.txt```
Тест на которых тестируются классы добавляются в этот репозиторий.

```Приветсвуется добавление своих тестов в этот репозиторий, для этого нужно сделать fork, добавить туда свой тест, а потом сделать pull request```

Чтобы класс можно было протестировать, библиотеки должны называться ```dynarr``` и ```rational ```

## Инструкция по подключению:
В своем репозитории создать файл: ```.github/workflows/tests.yml```
Содержимое файла:
```yaml
name: test_running

on:
  - workflow_dispatch
  - push

permissions:
  contents: write

jobs:
  run_tests_workflow:
    uses: rdinit/autoamting_full_tests/.github/workflows/run_tests.yaml@v1
```
Тесты будут запускаться при пуше изенений в репозиторий, но можно будет запускать выполнение вручную во вкладке Actions репозитория.
Подробнее можно почитать тут: https://docs.github.com/en/actions/using-workflows/triggering-a-workflow

