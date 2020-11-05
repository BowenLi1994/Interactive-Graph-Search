import re

with open('/home/bowen/igs_dataset/imagenet/structure_released') as f:
    lines = f.read().splitlines()

max_len=0
len_list=[0]*5

final_tokens=[]

for x in range(len(lines)):
    # print("line: ",x,":")
    tokens=re.split('<|>',lines[x])

    while("" in tokens) : 
        tokens.remove("")
    while("/synset" in tokens) : 
        tokens.remove("/synset")
    # print(tokens)
    final_tokens.append(tokens[0])
    # print(len(tokens))
    # len_list[len(tokens)]=len_list[len(tokens)]+1

node_list=[]

for t in final_tokens:
    node=[]
    t=t.replace("synset ","")
    pos1=t.find("wnid")
    pos2=t.find("words")
    pos3=t.find("gloss")
    s1=t[pos1:pos2]
    s2=t[pos2:pos3]
    s3=t[pos3:len(t)-1]
    # print(t)
    # print(s1[6:len(s1)-2])
    # print(s2[7:len(s2)-2])
    # print(s3[7:len(s3)-2])
    result=s1[6:len(s1)-2]+"\t"+s2[7:len(s2)-2]+"\t"+s3[7:len(s3)-2]
    # print()
    node_list.append(result)

node_list = list(dict.fromkeys(node_list))


with open('/home/bowen/igs_dataset/imagenet/imagenest.node', 'w') as file:
    for node in node_list:
        file.write('%s\n'%node)



# for x in node_list:
#     print(x)
    # print(tokens[1])
    # # if(len(tokens)==3):
    # #     print(tokens)
    # # # if(len(tokens)==2):
    # # #     print(tokens)
    # # # if(len(tokens)==3):
    # # #     print(tokens)
    
    # for y in range(len(tokens)):
    #     print(tokens[y])

    
