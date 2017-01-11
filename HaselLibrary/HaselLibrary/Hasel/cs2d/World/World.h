#pragma once

#include<map>
#include<list>

#include"math/MathInc.h"
#include"HaselAlias.h"

namespace hasel
{
	namespace shape
	{
		class Shape;
	}

	namespace cs2d
	{
		class RigidBody;
		class RigidBodyMold;
		class Callback;
		class RigidBodyStorage;
		class CallbackStorage;

		/// <summary>
		/// 衝突判定ファサード
		/// </summary>
		class World
		{
		private:
			sptr<RigidBodyStorage> rigidBodyStorage;
			sptr<CallbackStorage> callbackStorage;

			bool is_intersect(RigidBody* bodyA, RigidBody* bodyB);

		public:
			/// <summary>
			/// コンストラクタ
			/// </summary>
			World();

			/// <summary>
			/// 剛体を作成する
			/// </summary>
			/// <param name="mold">剛体鋳型</param>
			/// <returns>剛体への弱参照</returns>
			wptr<RigidBody> CreateRigidBody(const RigidBodyMold& mold);

			/// <summary>
			/// 剛体を削除する
			/// </summary>
			/// <param name="body">削除する剛体</param>
			void RemoveRigidBody(const wptr<RigidBody>& body);

			/// <summary>
			/// 剛体リストを取得する
			/// </summary>
			/// <returns>剛体リスト</returns>
			std::list<wptr<RigidBody>> GetRigidBodies()const;

			/// <summary>
			/// 剛体リストを取得する(属性指定付き)
			/// </summary>
			/// <param name="attribute">取得する剛体の持つ属性</param>
			/// <returns>属性リスト</returns>
			const std::list<wptr<RigidBody>>& GetRigidBodies(int attribute)const;

			/// <summary>
			/// 衝突コールバックを追加する
			/// </summary>
			/// <param name="callback">追加するコールバック</param>
			void AddCallback(const Callback& callback);

			/// <summary>
			/// 衝突コールバック
			/// </summary>
			/// <param name="callback"></param>
			void RemoveCallback(const Callback& callback);

			/// <summary>
			/// 衝突の検知及びコールバック関数の呼び出しを行う
			/// </summary>
			void ExecuteCollision();
		};
	}
}