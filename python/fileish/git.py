from subprocess import run, PIPE


class GitRepository:
    def __init__(self, **kwargs):
        self.url = kwargs.get('url')
        self.branch = kwargs.get('branch', 'master')
        self.path = kwargs.get('path', '')

    def __repr__(self):
        return f'git repository {self.url}/tree/{self.branch}/{self.path}'


class GitWorkingCopy:
    def __init__(self, directory, branch='master'):
        self.directory = directory
        self.branch = branch

    def checkout(self, git, path):
        run(['git', 'checkout', self.branch, '--', path], cwd=self.directory, check=True)


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
