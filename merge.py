import os
import glob
PATH_TO_TASK = '/home/dee/gos/ge'
RESULT_FILE = open('/home/dee/gos/ge/result.txt', 'rw+')
os.chdir(PATH_TO_TASK)

def find_first(iterator, condition, modifier=None, default=None):
    if modifier:
        related = (modifier(x) for x in iterator if condition(x))
    else:
        related = (x for x in iterator if condition(x))
    try:
        return related.next()
    except StopIteration:
        return default

def main():
    for root, sub_folders, files in os.walk('.'):
        if '.git' not in sub_folders:
            prog_filename = find_first(files, lambda x: x=='prog.cc')
            task_filename = find_first(files, lambda x: x=='task.txt')
            if prog_filename and task_filename and not os.path.islink(root):
                task_path = '{}/{}'.format(root, task_filename)
                prog_path = '{}/{}'.format(root, prog_filename)
                task_content = open(task_path, 'r').read()
                prog_content = open(prog_path, 'r').read()
                RESULT_FILE.write("\n\n{}\n\n".format(task_content))
                RESULT_FILE.write("\n\n{}\n\n".format(prog_content))
    RESULT_FILE.close()

if __name__ == "__main__":
    main()