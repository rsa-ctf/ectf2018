from flask import Flask, send_from_directory
from flask import render_template, request, session, make_response
from flask import Response

app = Flask(__name__, static_url_path='')

@app.route('/', methods=['GET'])
def hello():    
    return render_template('index.html')

@app.route('/hereisthesupersecureflag', methods=['GET'])
def fakelol():
	resp = "Go back and check the comments in the source"
	return Response(resp, mimetype='text')

@app.route('/robots.txt', methods=['GET'])
def robots():
	return send_from_directory('static', 'robots.txt')

@app.route('/entryonlyforthebrave', methods=['GET'])
def herring():
	return send_from_directory('static', 'challenge.txt')

@app.route('/stupidrottenlink', methods=['GET'])
def flagpage():
	return render_template("flag.html")

@app.route('/noobectf', methods=['GET'])
def flag():
	return Response("ECTF{no_5h17_5h3rlOcK_h3H3}", mimetype='text')


if __name__ == '__main__':
    app.run(host='0.0.0.0',port=40050, threaded=True, debug=False)