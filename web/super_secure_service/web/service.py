from flask import Flask
from flask import render_template, request, session, make_response
from flask import Response
import os
from functools import wraps
app = Flask(__name__)


@app.route('/', methods=['GET'])
def hello():
    return render_template('hello.html')


if __name__ == '__main__':
    app.secret_key = os.urandom(12)
    app.run(host='0.0.0.0',port=40005, threaded=True, debug=True)
        
