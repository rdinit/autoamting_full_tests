import os

def run_in_directory(start_dir):
    executables = []
    links = []
    dirtype = start_dir.split("_")[0]
    for file in os.listdir(start_dir):
        if file.endswith('cpp'):
            executables.append(f'add_executable({dirtype}_{file[:-4]} {file})')
            links.append(f'target_link_libraries({dirtype}_{file[:-4]} {dirtype})')
    with open(start_dir + '/CMakeLists.txt', 'w') as f:
        f.write('\n'.join(executables + links))

run_in_directory('rational_tests')
run_in_directory('dynarray_tests')