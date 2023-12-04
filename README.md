# autoamting_full_tests

Создать папку, где будут лежать тесты, которые добавляются разными людьми
например
```
.github/workflows
rational_tests/
  test_by_rdinit.cpp
  test_by_username.cpp
  test_....cpp
dynarray_tests/
  CMakeLists.txt
  test_by_rdinit.cpp
  test_by_username.cpp
  test_....cpp
prj.lab/
  rational/
    CMakeLists.txt
    files...
  dynarray/
    CMakeLists.txt
    files...
run_tests.sh
```

При запуске в репозитории копирует prj.lab в свою папку и прогоняет тесты, генерирует tests_status.md
