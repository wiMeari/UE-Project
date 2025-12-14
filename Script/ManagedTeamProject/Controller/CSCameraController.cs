using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using UnrealSharp;
using UnrealSharp.Attributes;
using UnrealSharp.CoreUObject;
using UnrealSharp.Engine;

namespace ManagedTeamProject.Controller
{
    [UClass]
    public class ACSCameraController : APlayerCameraManager
    {
        [UProperty(PropertyFlags.EditAnywhere)] public TSubclassOf<ACameraActor> CameraActorClass { get; set; }

        [UProperty(PropertyFlags.EditAnywhere)] public ACameraActor CameraActor { get; set; }

        protected override void BeginPlay()
        {
            base.BeginPlay();

            CameraActor = SpawnActor(CameraActorClass);
            CameraActor.SetActorLocation(new FVector(0, 0, 800));

        }

        public override void Tick(float deltaSeconds)
        {
            base.Tick(deltaSeconds);
        }
    }
}
