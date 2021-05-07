class LocalFile:
    def __init__(self, path: str):
        self.path = path

    def __repr__(self):
        return f'local file at {self.path}'

    def pull(self, destination: str):
        from shutil import copyfile
        from os import makedirs, path
        location = f'{destination}/{self.path}'
        location_dir = path.dirname(location)
        if not path.exists(location_dir):
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
        working_copy.checkout(self.git, self.path)
        return PulledFileFromGitRepository(self, location)


class PulledFileFromGitRepository:
    def __init__(self, source: FileInGitRepository, location: str):
        self.source = source
        self.location = LocalFile(location)

    def __repr__(self):
        return f'{self.location} pulled from {self.source}'

    def push(self):
        return self.source
