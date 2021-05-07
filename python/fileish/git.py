from subprocess import run, PIPE


class GitRepository:
    def __init__(self, **kwargs):
        self.url = kwargs.get('url')
        self.branch = kwargs.get('branch', 'master')
        self.path = kwargs.get('path', '')

    def __repr__(self):
        return f'git repository {self.url}/tree/{self.branch}/{self.path}'


class GitWorkingCopy:
    def __init__(self, directory):
        self.directory = directory
        self.__branch = None

    def branch(self):
        if not self.__branch:
            self.__branch = run(['git', 'branch', '--show-current'],
                                cwd=self.directory, check=True, stdout=PIPE).stdout.decode().strip()
        return self.__branch

    def checkout(self, git, path):
        run(['git', 'checkout', self.branch(), '--', path],
            cwd=self.directory, check=True)


class GitClient:
    def clone(self, repository: GitRepository, **kwargs):
        options = [
            '--single-branch',
            f'--branch={repository.branch}',
            '--no-checkout',
        ]
        run(['git', 'clone', *options, repository.url,
            kwargs['working_copy']], check=True)
        return GitWorkingCopy(kwargs['working_copy'])
