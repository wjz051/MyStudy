import os
import os.path

def change_qt_name(path, name):
    # print("root:[" + path + "," + name + "]")

    for item in os.listdir(path):
        if '.pro' in item:
            old=path+'/'+item
            new=path+'/'+name+".pro"
            print(old)
            print(new)
            os.rename(old,new)

        newitem = path +'/'+ item
        if os.path.isdir(newitem):
            change_qt_name(newitem, item)

def get_qt_pro_path(path,name):
    # print(path+name)
    for item in os.listdir(path+'/'+name):
        if item.endswith('.pro'):
            print(name+" \\")
        
        if name=='':
            newname=item
        else:
            newname=name+'/'+item

        # newname=name+'/'+item
        if os.path.isdir(path+'/'+newname):
            get_qt_pro_path(path,newname)

def add_dir_samp(path, name):
    for item in os.listdir(path):
        if item=='QtSamp.pro':
            continue
        if item.endswith('.pro') and 'samp' not in item:
            pathList=path.split("/")
            # print(pathList)
            newName=pathList[-2]+"_"+pathList[-1]
            pathList[-1]=newName
            newpath='/'.join(pathList)

            old=path+'/'+item
            new=path+'/'+newName+".pro"
            print(old)
            print(new)
            os.rename(old,new)
            

            print(path)
            print(newpath)
            os.rename(path,newpath)

        newitem = path + '/' + item
        if os.path.isdir(newitem):
            add_dir_samp(newitem, item)

listOld=['samp1','samp2','samp3','samp4','samp5','samp6','samp7','samp8','samp9']
listNew=['samp01','samp02','samp03','samp04','samp05','samp06','samp07','samp08','samp09']

def set_dir_num(path,name):
    for item in os.listdir(path):
        samp=item.split('_')[0]

        index=0
        for o in listOld:
            if o == samp:
                break
            index+=1

        if index<9 and item.endswith('.pro') and 'samp' in item:
            pathList=path.split("/")
            # print(pathList)
            newName=pathList[-1].replace(listOld[index],listNew[index])
            pathList[-1]=newName
            newpath='/'.join(pathList)

            old=path+'/'+item
            new=path+'/'+newName+".pro"
            print(old)
            print(new)
            os.rename(old,new)
            

            print(path)
            print(newpath)
            os.rename(path,newpath)

        newitem = path +'/'+ item
        if os.path.isdir(newitem):
            set_dir_num(newitem, item)

if __name__ == '__main__':
    # change_qt_name('C:/Users/WJZ/Documents/MyStudy/Qt/Code/QT5.9Samp', 'QtSamp')
    get_qt_pro_path('C:/Users/WJZ/Documents/MyStudy/Qt/Code/QT5.9Samp', '')
    # add_dir_samp('C:/Users/WJZ/Documents/MyStudy/Qt/Code/QT5.9Samp', 'QtSamp')
    # set_dir_num('C:/Users/WJZ/Documents/MyStudy/Qt/Code/QT5.9Samp', '')