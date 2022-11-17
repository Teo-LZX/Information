from crypt import methods
from unittest import result
from django.shortcuts import render
from flask import Flask, render_template
import flask
from flask import request
import pymysql
import json
from flask_socketio import SocketIO, emit 
import json


app = Flask(__name__)
socketio = SocketIO(app) 

def insert_user(name, psd):
    db = pymysql.connect(host='127.0.0.1', user='root', password='6356', database='product')
    cursor = db.cursor()
    sql = """INSERT INTO users_test(name, password) VALUES(%s, %s)"""
    print(name, psd)
    try:
        cursor.execute(sql, (name, psd))
        db.commit()
    except:
        print("error")
        db.rollback()
    db.close()
def check_user(name, psd, results):
    #print(results)
    for row in results:
        if str(row[0]) == name and str(row[1]) == psd:
            return True
    return False
@app.route('/')
def index():
    return render_template('login.html')
@app.route('/register', methods=['GET', 'POST'])
def register():
    if request.method == 'POST':
        user_info = request.form.to_dict()
        print(user_info)
        name = user_info.get('register-user-name')
        psd = user_info.get('register-password')
        insert_user(name, psd)
    return render_template('register_success.html')
@app.route('/login', methods=['GET', 'POST'])
def login():
    if request.method == 'POST':
        #从前端表单获取用户名、密码
        user_info = request.form.to_dict()   
        #print(user_info)           
        name = user_info.get('user-name')
        psd = user_info.get('password')
        db = pymysql.connect(host='127.0.0.1', user='root', password='6356', database='product')
        cursor = db.cursor()
        sql = "select * from users_test"
        try:
            cursor.execute(sql)
            db.commit()
        except:
            print('查询  error')
            db.rollback()
        results = cursor.fetchall()
        flag = check_user(name, psd, results)  #检查数据库中是否有该用户
        if flag:
            return render_template('login_success.html')
        else:
            return render_template('login_fail.html')
@app.route('/test')
def test():
    return render_template('test.html')
@app.route('/test2', methods=['GET', 'POST'])
def test2():
    print(request)
    return 'hello'
@app.route('/test3', methods=['GET', 'POST'])
def test3():
    return render_template('test2.html')

@app.route('/test4', methods=['GET', 'POST'])
def test4():
    s = ['bob', 'tom']
    return json.dumps(s)
@socketio.on('my event', namespace='/test') 
def test_message(message): 
    emit('my response', {'data': message['data']}) 
@socketio.on('my broadcast event', namespace='/test') 
def test_message(message): 
    emit('my response', {'data': message['data']}, broadcast=True) 
@socketio.on('connect', namespace='/test') 
def test_connect(): 
    emit('my response', {'data': 'Connected'}) 

@socketio.on('disconnect', namespace='/test') 
def test_disconnect(): 
    print('Client disconnected') 



if __name__ == '__main__':
    #app.run(host="0.0.0.0", port=5000)
    socketio.run(app,host='0.0.0.0' ,port=5000)