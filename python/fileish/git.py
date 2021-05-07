from subprocess import run, PIPE


class GitProfile:
    class User:
        def __init__(self, **options):
            self.email = options.get('email', None)
            self.name = options.get('name', None)

    def __init__(self, **options):
        self.user = GitProfile.User(**options.get('user', {}))


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

    def __repr__(self):
        return f'git working copy at {self.directory}'

    def branch(self):
        if not self.__branch:
            self.__branch = run(['git', 'branch', '--show-current'],
                                cwd=self.directory, check=True, stdout=PIPE).stdout.decode().strip()
        return self.__branch

    def checkout(self, path):
        run(['git', 'checkout', self.branch(), '--', path],
            cwd=self.directory, check=True)


class GitClient:
    def __init__(self, profile: GitProfile):
        self.profile = profile

    def clone(self, repository: GitRepository, **kwargs):
        options = [
            '--single-branch',
            f'--branch={repository.branch}',
            '--no-checkout',
        ]
        run(['git', 'clone', *options, repository.url,
            kwargs['working_copy']], check=True)
        working_copy = GitWorkingCopy(kwargs['working_copy'])
        run(['git', 'config', '--local', 'user.name',
            self.profile.user.name], cwd=working_copy.directory, check=True)
        run(['git', 'config', '--local', 'user.email',
            self.profile.user.email], cwd=working_copy.directory, check=True)
        return working_copy
