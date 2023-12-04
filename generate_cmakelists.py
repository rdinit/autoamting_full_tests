import os

def run_in_directory(start_dir):
    executables = []
    links = []
    for file in os.listdir(start_dir):
        if file.endswith('cpp'):
            executables.append(f'add_executable({file[:-4]} {file})')
            links.append(f'target_link_libraries({file[:-4]} {start_dir.split("_")[0]})')
    with open(start_dir + '/CMakeLists.txt', 'w') as f:
        f.write('\n'.join(executables + links))

run_in_directory('rational_tests')
run_in_directory('dynarray_tests')