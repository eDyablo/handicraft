from files import LocalFile, FileInGitRepository
from functools import partial
from git import GitClient
from manifest import load


manifest = load()

git = GitClient()

files = []

for file_manifest in manifest.get('files', []):
    if 'path' in file_manifest:
        files.append(LocalFile(file_manifest['path']))
    elif 'git' in file_manifest:
        files.append(FileInGitRepository(git, **file_manifest['git']))

print('INPUT')
print('\n'.join(map(repr, files)))

files = [file.pull('__tmp__') for file in files]

print('PULL')
print('\n'.join(map(repr, files)))

for file in files:
    with open(file.location.path) as stream:
        pass

files = [file.push() for file in files]

print('PUSH')
print('\n'.join(map(repr, files)))
