class LocalFile:
    def __init__(self, path: str):
        self.path = path

    def __repr__(self):
        return f'local file at {self.path}'

    def pull(self, destination: str):
        from shutil import copyfile
        from os import makedirs
        from os.path import dirname, exists
        location = f'{destination}/{self.path}'
        location_dir = dirname(location)
        if not exists(location_dir):
            makedirs(location_dir)
        return PulledLocalFile(self, copyfile(self.path, location))


class PulledLocalFile:
    def __init__(self, source: LocalFile, location: str):
        self.source = source
        self.location = LocalFile(location)

    def __repr__(self):
        return f'{self.location} pulled from {self.source}'

    def push(self):
        from shutil import copyfile
        copyfile(self.location.path, self.source.path)
        return self.source


class FileInGitRepository:
    from git import GitClient

    def __init__(self, git: GitClient, **kwargs):
        from git import GitRepository
        self.git = git
        self.repository = GitRepository(**kwargs)
        self.path = kwargs.get('path')

    def __repr__(self):
        return f'remote file at {self.repository}'

    def pull(self, destination: str):
        from re import sub
        from os import path
        from git import GitWorkingCopy
        directory = '/'.join(filter(None, [destination, sub(
            '[:~@]', '/', self.repository.url), self.repository.branch]))
        location = '/'.join(filter(None, [directory, self.path]))
        if path.exists(directory):
            working_copy = GitWorkingCopy(directory)
        else:
            working_copy = self.git.clone(
                self.repository, working_copy=directory)
        working_copy.checkout(self.path)
        return FileInGitWorkingCopy(self, working_copy, self.path)


class FileInGitWorkingCopy:
    from git import GitWorkingCopy

    def __init__(self, source: FileInGitRepository, working_copy: GitWorkingCopy, path: str):
        self.source = source
        self.working_copy = working_copy
        self.path = path
        self.location = LocalFile(f'{self.working_copy.directory}/{self.path}')

    def __repr__(self):
        return f'local file {self.path} at {self.working_copy}'

    def push(self):
        self.working_copy.push_changes(self.path)
        return self.source
