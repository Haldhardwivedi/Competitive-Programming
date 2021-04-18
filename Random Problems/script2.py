import sqlite3 

def createtable():
	conn = sqlite3.connect("little.db")
	cur  = conn.cursor()
	cur.execute("CREATE TABLE IF NOT EXISTS store(item TEXT, quantity INTEGER,price REAL)")
	conn.commit()
	conn.close()
def insert(item,quantity,price):
	conn = sqlite3.connect("little.db")
	cur  = conn.cursor()
	cur.execute("INSERT INTO store VALUES(?,?,?)",(item,price,quantity))
	conn.commit()
	conn.close()

createtable()
insert("table",2,100.0)
insert("chair",4,200.0)
insert("wine",100,6000)
def view():
	conn = sqlite3.connect("little.db")
	cur  = conn.cursor()
	cur.execute("SELECT * FROM store")
	rows=cur.fetchall()
	conn.commit()
	conn.close()
	return(rows)
def delete(item):
	conn = sqlite3.connect("little.db")
	cur  = conn.cursor()
	cur.execute("DELETE FROM store where item=?",(item,))
	conn.commit()
	conn.close()
delete("wine")
for item in view():
	print(item)
