![Banner](https://sun9-32.userapi.com/impg/od50QGoLipz4V-V4dAMGuJutI_2pT56TLts7rg/Xg-J92tylkU.jpg?size=2560x628&quality=96&sign=71b61c2f5d21688899fac8dc29df1c76&type=album)


[![Discord](https://img.shields.io/discord/1054720651069497345?label=&color=2d2d2d&labelColor=dddddd&style=for-the-badge&logo=Discord&logoColor=902121)](https://discord.gg/CzNvxakU3T)

# Aceid.cc Mini

Aceid.cc Mini - Бесплатный чит для игры "Warface", в нём присутствует минимальный функционал, и ничего лишнего!

### Функционал чита
 * Настройка отдачи
 * Настройка разброса
 * Отключение увода
 * Отключение затвора
 * Быстрая смена оружия

 * Аимбот
 * Триггер-бот
 * Прострел стен
 * Бесконечные патроны

 * Силуэты
 * Настройка FOV персонажа
 * Lua скриптинг

### Lua скриптинг
```lua
ACEID_API = {}
FUNCTIONS_TABLE = {}

function ACEID_API:new()
    local Methods = {}
    local Markers = {}

    Methods.ENABLED = 1;
    Methods.DISABLED = 0;

    -- Возвращает таблицу локального игрока
    function Methods:GetClientActor()
        return g_localActor;
    end

    -- Возвращает таблицу текущего предмета игрока
    function Methods:GetCurrentItem()
        return self:GetClientActor().inventory:GetCurrentItem();
    end

    -- Возвращает таблицу текущего оружия игрока
    function Methods:GetWeapon()
        return self:GetCurrentItem().weapon;
    end

    -- Возвращает массив всех сущностей на карте
    function Methods:GetEntities()
        return System.GetEntities();
    end

    -- Возвращает массив всех игроков на карте
    function Methods:GetPlayers()
        return System.GetEntitiesByClass("Player");
    end

    -- Получаем здоровье игрока
    function Methods:GetHealth(Target)
        if (Target.actor ~= nil) then
            return Target.actor:GetHealth();
        else
            return 0;
        end
    end
    
    -- Проверяем жив ли Actor
    function Methods:IsDead(Target)
        return self:GetHealth(Target) <= 0;
    end

    -- Получаем идентификатор команды
    function Methods:GetTeam(Target)
        if (g_gameRules.game ~= nil) then
            return g_gameRules.game:GetTeam(Target.id);
        else
            return 0;
        end
    end

    -- Сравниваем две команды
    function Methods:IsSameTeam(First, Second)
        return self:GetTeam(First) == self:GetTeam(Second)
    end

    -- Возращает TRUE если видно Entity
    function Methods:IsVisible(Target)
        return System.RayTraceCheck(System:GetViewCameraPos(), Target:GetBonePos("Bip01 Spine3"), 0, 0);
    end

    -- Меняем расположение камеры игрока на заданную позицию
    function Methods:SetViewPosition(Position)

        local Difference = DifferenceVectors(Position, System:GetViewCameraPos());
        Difference = NormalizeVector(Difference);

        self:GetClientActor():SetDirectionVector(Difference);
    end

    -- Возвращает Entity при столкновении луча
    function Methods:RayCast()
        local Position = System.GetViewCameraPos();
        local ScaledDirection = ScaleVector(System.GetViewCameraDir(), 100);
    
        local Result = { }
        Physics.RayWorldIntersection(Position, ScaledDirection, 1, ent_terrain + ent_static + ent_rigid + ent_sleeping_rigid + ent_living, g_localActor.id, NULL_ENTITY, Result);
    
        return Result[1]
    end

    -- Производит выстрелы
    function Methods:Shot(Count, Reload)
        self:GetWeapon():AutoShoot(Count, Reload)
    end

    -- Перезарядка оружия
    function Methods:Reload()
        self:GetWeapon():Reload()
    end

    -- Получает таблицу Screen
    function Methods:GetScreen()
        return UI.CurrentScreen;
    end

    -- Открывает игровую консоль
    function Methods:ShowConsole(Show)
        System.ShowConsole(Show);
    end
	
    -- Ищет функцию в таблице
	function Methods:FindFunction(Name, Handler)
		for key, Function in pairs(FUNCTIONS_TABLE) do
			if (Function.Name == Name 
            or Function.Function == Handler) then
				return key;
			end
		end
		return nil;
	end

    -- Регистрирует функцию в таблице
	function Methods:RegisterFunction(Name, Function)  
		local key = self:FindFunction(Name, Function);
		if (key == nil) then
			table.insert(FUNCTIONS_TABLE, { Name=Name, Function=Function });
            return;
		end
        if (FeedbackSystem ~= nil) then
            FeedbackSystem.OnEvent("objective_active_radar", {string={message=string.format("[!] Функция '%s', уже зарегистрирована.", Name)}});
        end
	end

    -- Удаляет функцию из таблицы
	function Methods:UnregisterFunction(Name)
		local key = self:FindFunction(Name);
		if (key ~= nil) then
			table.remove(FUNCTIONS_TABLE, key);
		end
	end

    setmetatable(Methods, self)
    self.__index = self;

    return Methods;
end

Aceid = ACEID_API:new();
```

Пример вх на LUA
```lua
if (System ~= nil and Script ~= nil) then
    local Actor = Aceid:GetClientActor();
    local Entities = Aceid:GetEntities();
    if (Actor ~= nil and Entities ~= nil) then

        for i in pairs(Entities)
        do
            local Entity = Entities[i]

            if (Entity ~= nil and Entity.actor)
            and (Entity ~= Actor)
            and (Aceid:IsDead(Entity) == false)
            and (Aceid:IsSameTeam(Actor, Entity) == false or Aceid:GetTeam(Actor) == 0)
            then
                if (Aceid:IsDead(Actor) == false) then
					FeedbackSystem.AddMarker("enemy_death_cam", Entity.id);    
                end
            end
        end
    end
end
```
