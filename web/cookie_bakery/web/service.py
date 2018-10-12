from flask import Flask
from flask import render_template, request, session, make_response
from flask import Response
import os
import binascii
from functools import wraps
app = Flask(__name__)
app.secret_key = os.urandom(12)
secret = binascii.b2a_hex(app.secret_key)
app.secret_key = secret
@app.route('/', methods=['GET'])
def hello():
    session['flag']="ECTF{D0n7_giv3_s3cr375_@waY}"
    return render_template('hello.html', secret=secret)


if __name__ == '__main__':
    app.run(host='0.0.0.0',port=40101, threaded=True, debug=False)
        
