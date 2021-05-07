from files import LocalFile, FileInGitRepository
from functools import partial
from git import GitClient, GitProfile
from manifest import load


manifest = load()

git = GitClient(GitProfile(
    user={'name': 'edyablo', 'email': 'eyablonsky@gmail.com'}))

files = []

for file_manifest in manifest.get('files', []):
    if 'path' in file_manifest:
        files.append(LocalFile(file_manifest['path']))
    elif 'git' in file_manifest:
        files.append(FileInGitRepository(git, **file_manifest['git']))

print('INPUT')
print('\n'.join(map(repr, files)))

print('PULL')
files = [file.pull('__tmp__') for file in files]

print('PULLED')
print('\n'.join(map(repr, files)))

for file in files:
    with open(file.location.path, 'r') as stream:
        lines = [str(int(line) + 1) for line in map(str.strip, stream)]
    with open(file.location.path, 'w') as stream:
        for line in lines:
            stream.write(f'{line}\n')

print('PUSH')

files = [file.push() for file in files]

print('PUSHED')
print('\n'.join(map(repr, files)))
