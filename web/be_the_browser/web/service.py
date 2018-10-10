from flask import Flask
from flask import render_template, request, session, make_response
from flask import Response
import os
from functools import wraps
app = Flask(__name__)

def decorate(func):
    @wraps(func)
    def wrapper(*args, **kwargs):
        if request.headers.get('User-Agent')==None:
            return Response('User-Agent not set', status=400)
        if request.headers.get('Host')==None:
            return Response('Host Header is not set', status=400)
        if request.headers.get('User-Agent')!='nc':
            return Response('Only nc as User-Agent accepted', status=400)
        if request.headers.get('Host')!='ectf.proxy':
            return Response('Unknown Host', status=400)
        return func(*args, **kwargs)
    return wrapper


@app.route('/', methods=['GET'])
@decorate
def hello():

    if not session.get('logged_in'):
        return render_template('hello.html')
    else:
        return render_template('flag_redirect.html')

@app.route('/auth', methods=['GET', 'POST'])
@decorate
def auth():
    if request.method == 'GET':
        return render_template('login.html')
    else:
        if request.form['pass']=='onehellofapassword' and request.form['user']=='realuser':
            session['logged_in']=True
            resp = make_response(render_template('logged_in.html'))
            resp.set_cookie('name', 'ECTF{7his_is_n07_th3_flag}')
            return resp
        else:
            return render_template('wrong_cred.html')

@app.route('/flag', methods=['GET'])
@decorate
def flag():
    if not session.get('logged_in'):
        return render_template('hello.html')
    cookie = request.cookies.get('name')
    if cookie !='ECTF{7his_is_n07_th3_flag}':
        return Response('Bad Request', status=400)
    return render_template('flag.html')



if __name__ == '__main__':
    app.secret_key = os.urandom(12)
    app.run(host='0.0.0.0',port=40001, threaded=True)
