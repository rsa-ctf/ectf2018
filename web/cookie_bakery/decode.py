import sys
import hashlib
from itsdangerous import URLSafeTimedSerializer
from flask.sessions import TaggedJSONSerializer

def decode_flask_cookie(secret_key, cookie_str):
    salt = 'cookie-session'
    serializer = TaggedJSONSerializer()
    signer_kwargs = {
        'key_derivation': 'hmac',
        'digest_method': hashlib.sha1
    }
    s = URLSafeTimedSerializer(secret_key, salt=salt, serializer=serializer, signer_kwargs=signer_kwargs)
    return s.loads(cookie_str)


if __name__ == '__main__':
    if(len(sys.argv))!=3:
        print "Usage decode.py <cookie> <secret>"
        sys.exit()
    cookie = sys.argv[1]
    secret = sys.argv[2]
    print decode_flask_cookie(secret, cookie)

