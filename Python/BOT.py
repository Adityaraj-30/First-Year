import discord
import random
from discord import user
from discord.ext import commands
import bs4
from urllib.request import urlopen
import datetime

#setting bot prefix
client=commands.Bot(command_prefix='@')

@client.event
async def on_ready():
    print('BOT IS READY')
@client.event    
async def on_member_join(member):
    print(f'{member} has joined a server.')

@client.event
async def on_member_remove(member):
    print(f'{member} has left a server.')


@client.command()
async def ping(ctx):
    await ctx.send(f'Pong! {round(client.latency*100)}ms')

@client.command()
async def hello(ctx):
    await ctx.send(f'hello buddy! {round(client.latency*100)}ms')    

@client.command(aliases=['random','test'])
async def _random(ctx,* ,question):
    responses=['It is certain.',
               'Very doubtful.',
               'Yes-definitely.',
               'My reply is no.',
               'Ask again later.',
               'Outlook not so good.',
               'Most likely.',
               'Cannot predict now.',
               'Concentrate on studies.']
    await ctx.send(f'Question: {question}\nAnswer: {random.choice(responses)}')  


@client.command()
async def clear(ctx, amount=5):
    await ctx.channel.purge(limit=amount)

@client.command()
async def kick(ctx, member:discord.Member, * , reason=None):
    await member.kick(reason=reason)

@client.command()
async def ban(ctx, member:discord.Member, * , reason=None):
    await member.ban(reason=reason)  
    await ctx.send(f'Banned {member.mention}')

@client.command()
async def unban(ctx, *,member):
    banned_users=await ctx.guild.bans()
    member_name,member_discriminator=member.split('#')

    for ban_entry in banned_users:
        user = ban_entry.user

        if(user.name, user.discriminator)==(member_name,member_discriminator):
            await ctx.guild.unban(user)
            await ctx.send(f'unbanned {user.mention}')
            return

@client.command()
async def news(ctx):
   url="https://news.google.com/news/rss"
   cl = urlopen(url)
   xml_page = cl.read()
   cl.close()
   page = bs4.BeautifulSoup(xml_page, "html.parser")
   list = page.findAll("item")
   await ctx.send(f"Today's Top Headlines Are------>\n")

   for news in list:
#         await ctx.send(news.title.text)
#         await ctx.send(f' \n {round(client.latency*100)}ms')
#         # await ctx.send(news.pubDate.text)
#         # await ctx.send(news.link.text)
        
       
        try:
       # for news in list:
            await ctx.send(news.title.text)
            await ctx.send(f' \n {round(client.latency*100)}ms')
            await ctx.send(news.pubDate)
            # print(new.pubDate.text)
            # print("-"*60)s
            #print(news.link.text)
            
        except Exception as e:
            print(e)        







    



# async def on_message(message):
#         if message.content.startwith('@hello'):
#             channel=message.channel
#             await channel.send('Say hello!')

            # def check(m):
            #     return m.content=='hello'and m.channel==channel

            # msg=await client.wait_for('message',check=check)
            # await channel.send('Hello{.author}!'.format(msg))        

#bot token
client.run("ODU1MTE1MDk2MTY2MTA1MTIw.YMtx_g.OdFGe_I8tVRj5YzFrp7L3fQxs7c")    