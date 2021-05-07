import cerberus
import yaml

schema = {
    'files': {
        'type': 'list',
        'schema': {
            'oneof': [{
                'type': 'dict',
                'schema': {
                    'path': {
                        'required': True,
                        'type': 'string'
                    }
                }
            }, {
                'type': 'dict',
                'schema': {
                    'git': {
                        'type': 'dict',
                        'schema': {
                            'url': {
                                'required': True,
                                'type': 'string'
                            },
                            'branch': {
                                'required': False,
                                'type': 'string'
                            },
                            'path': {
                                'required': False,
                                'type': 'string'
                            }
                        }
                    }
                }
            }]
        }
    }
}


def load(path: str = 'manifest.yaml'):
    validator = cerberus.Validator()
    validator.validate(yaml.full_load(open(path)), schema)
    if validator.errors:
        raise Exception(validator.errors)
    return validator.document
